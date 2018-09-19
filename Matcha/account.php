<html>
	<head>
		<link rel="stylesheet" type="text/css" href="CSS/account.css">
		<script>
			function openTab(tabName)
			{
				var		i;
				var		x = document.getElementsByClassName("tab");

				for (i = 0; i < x.length; i++)
				{
					x[i].style.display = "none";
				}
				document.getElementById(tabName).style.display = "block";
			}
		</script>
	</head>
	<body>
		<div id="title">ACCOUNT</div>
			<div id="background">
				<div id="portals">
					<a href="index.php"><img src="pictures/home.png" title="Home" alt="Home" class="pictures"></a>
					<a href=""><img src="pictures/matches.png" title="Matches" alt="Matches" class="pictures"></a>
					<a href=""><img src="pictures/viewers.png" title="Viewers" alt="Viewers" class="pictures"></a>
					<a href="account.php"><img src="pictures/Settings-64.png" title="Account" alt="Settings" class="pictures"></a>
				</div>
				<div class="textboxes">
					<form action="update_bio.php">
						<table>
							<tr><td class="tableHeader">Biography</td></tr>
							<tr><td><textarea class="textboxes" cols=86 rows=20 maxlength="500" placeholder="Max Length: 500 Characters. Update your biography..." name="n_biography"></textarea></td></tr>
						</table>
						<input class="button" type="submit" name="update" value="Update">
					</form>
				</div>
				<div id="sidebar">
					<div id="information">
						<ul>
							<li><a href="javascript:void(0)" onclick='openTab("general")'>General</a></li>
							<li><a href="javascript:void(0)" onclick='openTab("change")'>Edit</a></li>
						</ul>
						<div id="all" class="tab">
						</div>
						<div id="general" class="tab">
							<br><br>
							<a href="match.php">Matches</a>
							<br><br>
							<a href="viewers.php">Viewers</a>
							<br><br>
							<a href="recent_like">Recently Liked</a>
						</div>
						<br><br>
						<div id="change" class="tab">
							<a href="account_cp.php">Change Password</a> <!-- Password Change -->
							<br><br>
							<a href="account_ema.php">Change Email Address</a> <!-- Change Email Adress -->
							<br><br>
							<a href="account_upload.php">Upload Pictures</a> <!-- Upload Pictures  && SAVE -->
							<br><br>
							<a href="account_user.php">Change Name</a> <!-- Change Current Name / Last Name -->
						</div>
					</div>
				</div>
				<div id="pPic"></div>
				<?php

					if ($_GET['email'] == "new")
					{
						echo '<div><f_success>Your email has successfully been Updated.</f_success></div>';
					}

					if ($_GET['pass'] == "update")
					{
						echo '<div><f_success>Your password has successfully been Updated.</f_success></div>';
					}

					if ($_GET['bio'] == "new")
					{
						echo '<div><f_success>Your biography has successfully been Updated.</f_success></div>';
					}

					if ($_GET['name'] == "new")
					{
						echo '<div><f_success>Your first and last name has successfully been Updated.</f_success></div>';
					}

					?>
			</div>
	</body>
</html>