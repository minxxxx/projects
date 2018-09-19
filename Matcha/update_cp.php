<?php

include('connect.php');

$email = $_GET['email'];
$password = hash('whirlpool', $_GET['password']);
$n_password = hash('whirlpool', $_GET['n_password']);

$conn = Connect();
$st = $conn->prepare("SELECT * FROM `users` WHERE email = :email");
$st->bindParam(':email', $email);
$st->execute();
if ($st->rowCount() == 1)
{
	$passtd = $conn->prepare("SELECT * FROM `users` WHERE password = :password");
	$passtd->bindParam(':password', $password);
	$passtd->execute();
	if ($passtd->rowCount() == 1)
	{
		if ($n_password == "")
		{
			header("refresh:0;url=account_cp.php?pass=clear");
		}
		else
		{
			$npSt = $conn->prepare("UPDATE `users` SET `password` = :n_password WHERE `password` = :password");
			$npSt->bindParam(':password', $password);
			$npSt->bindParam(':n_password', $n_password);
			$npSt->execute();
			header("refresh:0;url=account.php?pass=update");
		}
	}
}
else
{
	header("refresh:0;url=account_cp.php?email=invalid");
}

?>