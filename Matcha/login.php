<?php

session_start();

include('connect.php');

ini_set("display_startup_errors", 1);
ini_set("display_errors", 1);

$email = $_GET['email'];

$pass = hash("whirlpool", $_GET['password']);

$conn = Connect();
$st = $conn->prepare("SELECT * FROM `users` WHERE `email` = :email AND `password` = :password");
$st->bindParam(":email", $email);
$st->bindParam(":password", $pass);
$st->execute();
$row = $st->fetch(PDO::FETCH_ASSOC);
if ($st->rowCount() == 1)
{
	$_SESSION['email'] = $email;
	$email = $_SESSION['email'];
	header("refresh:0;url=account.php?logged=$email");
}
else
{
	header("refresh:0;url=index.php?error=true");
}

?>