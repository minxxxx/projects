<?php

include('connect.php');

$email = $_GET['email'];
$password = hash("whirlpool", $_GET['password']);
$firstname = $_GET['first_name'];
$n_firstname = $_GET['n_first_name'];
$lastname = $_GET['last_name'];
$n_lastname = $_GET['n_last_name'];

$conn = Connect();
$st = $conn->prepare("SELECT * FROM `users` WHERE email = :email");
$st->bindParam(':email', $email);
$st->execute();
if ($st->rowCount() == 1)
{
	$passt = $conn->prepare("SELECT * FROM `users` WHERE password = :password");
	$passt->bindParam(':password', $password);
	$passt->execute();
	if ($passt->rowCount() == 1)
	{
		// FIRST NAME
        if ($n_firstname == "")
		{
            $newNameSt = $conn->prepare("SELECT * FROM `users` WHERE `first_name` = :n_firstname");
			$newNameSt->bindParam(':n_firstname', $firstname);
			$newNameSt->execute();
		}
		else
		{
			$newNameSt = $conn->prepare("UPDATE `users` SET `first_name` = :n_firstname WHERE `email` = :email");
			$newNameSt->bindParam(':n_firstname', $n_firstname);
			$newNameSt->bindParam(':email', $email);
			$newNameSt->execute();
		}

		// LAST NAME
	    if ($n_lastname == "")
		{
			$newLNameSt = $conn->prepare("SELECT * FROM `users` WHERE `last_name` = :n_lastname");
			$newLNameSt->bindParam(':n_lastname', $lastname);
			$newLNameSt->execute();
		}
		else
		{
			$newLNameSt = $conn->prepare("UPDATE `users` SET `last_name` = :n_lastname WHERE `email` = :email");
			$newLNameSt->bindParam(':n_lastname', $n_lastname);
			$newLNameSt->bindParam(':email', $email);
			$newLNameSt->execute();
		}
		header("refresh:0;url=account.php?name=new");
	}
	else
	{
		header("refresh:0;url=account_ema.php?password=invalid");
	}
}
else
{
	header("refresh:0;url=account_user.php?email=invalid");
}

?>