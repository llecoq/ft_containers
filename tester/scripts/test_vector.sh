echo "*--------------------------------------------------------*"
echo "			 VECTOR"
echo "vector std execution time :"
make clean
make DFLAGS=-Dstd_lib=1
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_std.test
echo "vector ft execution time :"
make clean
make DFLAGS=-Dstd_lib=0
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_ft.test
echo "diff :"
diff tester/tester_results/vector_ft.test tester/tester_results/vector_std.test
echo "		       VECTOR DONE"
echo "*--------------------------------------------------------*"

# leaks -atExit -- ./ft_containers ft vector