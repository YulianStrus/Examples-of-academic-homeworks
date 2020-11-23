<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>
<h1>PHP Провека каждой переменной</h1>

<?php
// определите переменные и задайте пустые значения
$name = $email = $gender = $comment = $website = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = test_input($_POST["name"]);
  $email = test_input($_POST["email"]);
  $website = test_input($_POST["website"]);
  $comment = test_input($_POST["comment"]);
  $gender = test_input($_POST["gender"]);
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>

<h2>Пример проверки формы PHP</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">  
  Имя: <input type="text" name="name">
  <br><br>
  E-mail: <input type="email" name="email">
  <br><br>
  Тема: <input type="text" name="subject">
  <br><br>
  Комментарий: <textarea name="message" rows="5" cols="40"></textarea>
  <br><br>
  <input type="submit" name="submit" value="Отправить">  
</form>

<?php
echo "<h2>Ваш ввод:</h2>";
echo $name;
echo "<br>";
echo $email;
echo "<br>";
echo $website;
echo "<br>";
echo $comment;
echo "<br>";
echo $gender;
?>

</body>
</html>