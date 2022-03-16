echo "*--------------------------------------------------------*"
echo "			 VECTOR"
echo "vector std execution time :"
/usr/bin/time ./ft_containers std vector > tester/tester_results/vector_std.test
echo "vector ft execution time :"
/usr/bin/time ./ft_containers ft vector > tester/tester_results/vector_ft.test
echo "diff :"
diff tester/tester_results/vector_ft.test tester/tester_results/vector_std.test
echo "		       VECTOR DONE"
echo "*--------------------------------------------------------*"

# leaks -atExit -- ./ft_containers ft vector