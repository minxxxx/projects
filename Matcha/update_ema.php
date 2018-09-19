<?php

include('connect.php');

session_start();

$email = $_GET['email'];
$password = hash("whirlpool", $_GET['password']);
$n_email = $_GET['n_email'];
$_SESSION['email'] = $n_email;

$conn = Connect();
$st = $conn->prepare("SELECT * FROM `users` WHERE email = :email");
$st->bindParam(':email', $email);
$st->execute();
if ($st->rowCount() == 1)
{
	$pasSt = $conn->prepare("SELECT * FROM `users` WHERE password = :password");
	$pasSt->bindParam(':password', $password);
	$pasSt->execute();
	if ($pasSt->rowCount() == 1)
	{
		$st3 = $conn->prepare("SELECT * FROM `users` WHERE `email` = :n_email");
		$st3->bindParam(':n_email', $n_email);
		$st3->execute();
		if ($st3->rowCount() == 1)
		{
			header("refresh:0;url=account_ema.php?email=exists");
		}
		else
		{
			$st2 = $conn->prepare("UPDATE `users` SET `email` = :n_email WHERE `email`=:email");
			$st2->bindParam(':email', $email);
			$st2->bindParam(':n_email', $n_email);
			$st2->execute();
			header("refresh:0;url=account.php?email=new");
		}
	}
}
else
{
	header("refresh:0;url=account_ema.php?email=invalid");
}

?>