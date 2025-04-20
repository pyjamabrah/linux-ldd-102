while : ; do
    sudo insmod exercise_02.ko
    sleep 1
    sudo rmmod exercise_02
    sleep 1
done
