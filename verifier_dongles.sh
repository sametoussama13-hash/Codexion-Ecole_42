#!/usr/bin/env bash
set -euo pipefail

cd -- "$(dirname -- "${BASH_SOURCE[0]}")"
work=$(mktemp -d)
trap 'rm -rf -- "$work"' EXIT
cp -- Makefile ./*.c ./*.h "$work/"
cp -R -- parsing outils coder_fonction dongle_fonction build "$work/"
CCACHE_DISABLE=1 make -s -B -C "$work"

status=0
for coders in 1 2 3; do
    printf '\n%s coder(s) — fifo\n' "$coders"
    # Le cas solo doit atteindre son burnout après 1 000 ms.
    if timeout 3s "$work/codexion" "$coders" 1000 40 5 5 3 20 fifo > "$work/trace"; then
        if awk -v coders="$coders" '
            $3 == "is" && $4 == "compiling" { compiles[$2]++ }
            $2 == 1 && $3 == "burned" && $4 == "out" { solo_burnout = 1 }
            END {
                for (i = 1; i <= coders; i++)
                    printf "  Coder %d — %d compilation(s)\n", i, compiles[i]
                if (coders == 1) {
                    if (compiles[1] || !solo_burnout) {
                        print "  Attendu en solo — zéro compilation et un burnout."
                        exit 1
                    }
                } else {
                    for (i = 1; i <= coders; i++)
                        if (compiles[i] < 3) {
                            print "  Attendu — au moins trois compilations par coder."
                            exit 1
                        }
                }
            }
        ' "$work/trace"; then
            printf '  Résultat attendu observé.\n'
        else
            status=1
        fi
    else
        result=$?
        if [[ $result == 124 ]]; then
            printf '  Toujours actif après 3 s. Vérifie en premier l’ordre des verrous.\n'
        else
            printf '  Le programme a quitté avec le code %s.\n' "$result"
        fi
        status=1
    fi
    if [[ -s "$work/trace" ]]; then
        sed -n '1,12p' "$work/trace"
    fi
done
exit "$status"
