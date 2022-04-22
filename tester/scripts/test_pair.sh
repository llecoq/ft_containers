echo "		           PAIR"
echo "*--------------------------------------------------------*"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "pair std execution time :"
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_std.test
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "pair ft execution time :"
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_ft.test
echo "diff :"
diff tester/tester_results/pair_ft.test tester/tester_results/pair_std.test
echo "		         PAIR DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector