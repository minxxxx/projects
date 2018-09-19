<?php

include("connect.php");

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

$email = $_GET['email'];
$password = $_GET['password'];
$first_name = $_GET['first_name'];
$last_name = $_GET['last_name'];
$age = $_GET['age'];
$gender = $_GET['gender'];
$preference = $_GET['preference'];
$biography = $_GET['biography'];
$location = $_GET['location'];

$conn = Connect();
$st = $conn->prepare("SELECT * FROM `users` WHERE `email` = :email");
$st->bindParam(':email', $email);
$st->execute();
$row = $st->fetch(PDO::FETCH_ASSOC);
if ($email == "" || $password == "" || $first_name == "" || $last_name == "" || $age == "" || $gender == "Select Gender" || $preference == "Select Preference" || $biography == "" || $location == "Select Country")
{
	header("refresh:0;url=register.php?error=true");
}
elseif ($st->rowCount() > 0)
{
	header("refresh:0;url=register.php?email=used");
}
else
{
	$password = hash("whirlpool", $password);
	$sql = $conn->prepare("INSERT INTO `users` (email, password, first_name, last_name, age, gender, preference, biography, location) VALUES (:email,:password,:first_name,:last_name,:age,:gender,:preference,:biography, :location)");
	$sql->bindParam(':email', $email);
	$sql->bindParam(':password', $password);
	$sql->bindParam(':first_name', $first_name);
	$sql->bindParam(':last_name', $last_name);
	$sql->bindParam(':age', $age);
	$sql->bindParam(':gender', $gender);
	$sql->bindParam(':preference', $preference);
	$sql->bindParam(':biography', $biography);
	$sql->bindParam(':location', $location);
	
	$sql->execute();
	header("refresh:0;url=index.php?registered=true");
}

?>