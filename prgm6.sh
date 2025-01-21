echo "Enter the number"
read n
x=0
y=1
ch=0
echo $x
echo $y
for((i=1;i<=$n-2;i++))
do
	sum=$(($x+$y))
	echo $sum
	if (($ch==0))
	then
		x=$(($sum))
		ch=1
	else
		y=$(($sum))
		ch=0
	fi
done
