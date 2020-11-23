
<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>
<h1>Days</h1>
  <h1>Exercise 1</h1>
<?php

	$month = 9;

	echo "Put month number (between 1 and 12), please: ";
	

		if ($month == 1||$month ==3||$month ==5||$month ==7||$month ==8||$month ==10||$month ==12)
		{
			echo "Days in month $month is: 31";
		}
		elseif ($month == 4||$month ==6||$month ==9||$month ==11)	
		{
			echo "Days in month $month is: 30";
		}
		elseif ($month == 2)
		{
			echo "Days in month $month is: 28";
		}
		else echo "Error number!";
?>

  <h1>Exercise 2</h1>
<?php
$str='radar';
$strrev=strrev($str);
echo "is ".$str." a palindrome?: "; 
if ($str==$strrev) {echo "true";}
else {echo "false";}
?>

  <h1>Exercise 3</h1>
<?php
$count = 0;
$data ="a nut for a jar of tuna";

foreach (count_chars($data, 0) as $i => $val) {
   if ("a" == chr($i)||"e" == chr($i)||"i" == chr($i)||"o" == chr($i)) 
   {
   	$count+=$val;
   }
}
echo "Number of vowel letters = $count";
?>

</body>
</html>