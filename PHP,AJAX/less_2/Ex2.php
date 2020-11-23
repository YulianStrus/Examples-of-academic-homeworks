<!DOCTYPE HTML>
<html>
 <head>
  <meta charset="utf-8">
  <title>Chess board</title>
 </head>
 <body>
  <h1>Exercise 1</h1>

<table width="270px" border="1">

<?php
      for($row=1;$row<=8;$row++)
    {
          echo "<tr>";
          for($col=1;$col<=8;$col++)
      {
          $total=$row+$col;
          if($total%2==0)
      {
          echo "<td height=30px width=30px bgcolor=#FFFFFF></td>";
          }
      else
      {
          echo "<td height=30px width=30px bgcolor=#000000></td>";
          }
          }
          echo "</tr>";
    }
?>

  </table>

<br><h1>Exercise 2</h1>
<table border="1" cellpadding="3px" cellspacing="0px">
<?php
  for ($i=0;$i<=9;$i++)
  {echo "<tr>";
    for ($j=0; $j <=9; $j++) { 
      echo "<td>$i$j</td>";
    }
    echo "</tr>";
  }
?> </table>

<br><h1>Exercise 3</h1>
<table border="1" cellpadding="3px" cellspacing="0px">
<?php
$sum="";
  for ($i=1;$i<=6;$i++)
  {echo "<tr>";
    for ($j=1; $j <=5; $j++) { 
      $sum=$i*$j;
      echo "<td>$i * $j = $sum</td>";
    }
    echo "</tr>";
  }
?> </table>

<br><h1>Exercise 4</h1>
<?php
$countries = array( "Italy"=>"Rome", "Luxembourg"=>"Luxembourg", "Belgium"=> "Brussels", "Denmark"=>"Copenhagen", "Finland"=>"Helsinki", "France" => "Paris", "Slovakia"=>"Bratislava", "Slovenia"=>"Ljubljana", "Germany" => "Berlin", "Greece" => "Athens", "Ireland"=>"Dublin", "Netherlands"=>"Amsterdam", "Portugal"=>"Lisbon", "Spain"=>"Madrid", "Sweden"=>"Stockholm", "United Kingdom"=>"London", "Cyprus"=>"Nicosia", "Lithuania"=>"Vilnius", "Czech Republic"=>"Prague", "Estonia"=>"Tallinn", "Hungary"=>"Budapest", "Latvia"=>"Riga", "Malta"=>"Valletta", "Austria" => "Vienna", "Poland"=>"Warsaw");
  
  asort($countries);

  foreach ($countries as $key => $cap) {
    echo "The capital of $key is $cap<br>";
  }

?>

<br><h1>Exercise 5</h1>
<?php
$month_temp = array( 78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 75, 76, 73, 68, 62, 73, 72, 65, 74, 62, 62, 65, 64, 68, 73, 75, 79, 73);
  
  $temp_array = explode (',',$month_temp);
  $tot_temp = 0;
  $temp_array_length = count($temp_array);

  foreach ($Ttemp_array as $value) {
    $avg_high_temp = $tot_temp/$temp_array_length;
    echo "Average Temperature is: " . $avg_high_temp." ";
    sort ($temp_array);
    echo "<br>List of seven lovwest temperatures: ";
    $i=0;
  }
?>
 </body>
</html>