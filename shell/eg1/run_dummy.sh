exp_times=100
result_file=tmp_result
echo "" > $result_file
for i in `seq 1 $exp_times`
do
    bash ./run_exp.sh | sed -n '2 p' | awk '{print $2}' >> $result_file
done
awk 'BEGIN{cnt=0} {sum+=$1;cnt++;} END{print sum/cnt}' $result_file

## run under different configuration and use gnuplot to plot
