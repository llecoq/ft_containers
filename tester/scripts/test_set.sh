echo "		           SET"
echo "*--------------------------------------------------------*"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "set std execution time :"
/usr/bin/time ./ft_containers set > tester/tester_results/set_std.test
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "set ft execution time :"
/usr/bin/time ./ft_containers set > tester/tester_results/set_ft.test
echo "diff :"
diff tester/tester_results/set_ft.test tester/tester_results/set_std.test
echo "		         SET DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector