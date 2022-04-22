echo "*--------------------------------------------------------*"
echo "			 VECTOR"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "vector std execution time :"
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_std.test
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "vector ft execution time :"
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_ft.test
echo "diff :"
diff tester/tester_results/vector_ft.test tester/tester_results/vector_std.test
echo "		       VECTOR DONE"
echo "*--------------------------------------------------------*"

# leaks -atExit -- ./ft_containers ft vector