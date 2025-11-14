src="e"
bf="e_bf"

make ${src}
make ${bf}

while true; do
    python ./gen.py > ${src}.in
    ./${src} < ${src}.in > ${src}.out;
    ./${bf} < ${src}.in > ${src}.ans;
    if diff -w ${src}.out ${src}.ans; then
        echo "AC"
    else
        echo "WA"
        break
    fi
done
