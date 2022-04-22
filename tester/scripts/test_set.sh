echo "		           SET"
echo "*--------------------------------------------------------*"
echo "set std execution time :"
make clean
make DFLAGS=-Dstd_lib=1
/usr/bin/time ./ft_containers set > tester/tester_results/set_std.test
echo "set ft execution time :"
make clean
make DFLAGS=-Dstd_lib=0
/usr/bin/time ./ft_containers set > tester/tester_results/set_ft.test
echo "diff :"
diff tester/tester_results/set_ft.test tester/tester_results/set_std.test
echo "		         SET DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector