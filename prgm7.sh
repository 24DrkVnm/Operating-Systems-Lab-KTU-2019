echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "1.multiplication 2.addition 3.subtraction 4.division"
read ch
case $ch in
1)prod=$(($a*$b))
echo "product is $prod";;
2)sum=$(($a+$b))
echo "sum is $sum";;
3)diff=$(($a-$b))
echo "difference is $diff";;
4)qou=$(($a/$b))
echo "quotient is $qou"
esac
