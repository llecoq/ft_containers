echo "		           PAIR"
echo "*--------------------------------------------------------*"
echo "pair std execution time :"
make clean
make DFLAGS=-Dstd_lib=1
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_std.test
echo "pair ft execution time :"
make clean
make DFLAGS=-Dstd_lib=0
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_ft.test
echo "diff :"
diff tester/tester_results/pair_ft.test tester/tester_results/pair_std.test
echo "		         PAIR DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector