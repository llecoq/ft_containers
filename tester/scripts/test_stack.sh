echo "*--------------------------------------------------------*"
echo "			  STACK"
echo "stack std execution time :"
make clean
make DFLAGS=-Dstd_lib=1
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_std.test
echo "stack ft execution time :"
make clean
make DFLAGS=-Dstd_lib=0
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_ft.test
echo "diff :"
diff tester/tester_results/stack_ft.test tester/tester_results/stack_std.test
echo "		        STACK DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector