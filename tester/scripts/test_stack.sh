echo "*--------------------------------------------------------*"
echo "			  STACK"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "stack std execution time :"
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_std.test
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "stack ft execution time :"
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_ft.test
echo "diff :"
diff tester/tester_results/stack_ft.test tester/tester_results/stack_std.test
echo "		        STACK DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector