# cd ..
echo "stack std execution time :"
/usr/bin/time ./ft_containers std stack > tester/tester_results/stack_std.test
echo "stack ft execution time :"
/usr/bin/time ./ft_containers ft stack > tester/tester_results/stack_ft.test
echo "diff :"
diff tester/tester_results/stack_ft.test tester/tester_results/stack_std.test

# leaks -atExit -- ./ft_containers ft vector