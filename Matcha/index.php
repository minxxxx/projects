<html>
    <head>
        <title>Matcha</title>
        <link rel="stylesheet" type="text/css" href="CSS/index.css">
    </head>
    <body>
        <div id="titlebox">
			<div id="portals">
				<a href="index.php"><img src="pictures/home.png" title="Home" alt="Home" class="pictures"></a>
			</div>
            <center><a href="index.php" id="title">MATCHA</center></a>
			<div id="msgs">
				<?php
				
				//Random pickup lines
				$slogans = array("Are you a magician? Because whenever I look at you, everyone else disappears!", "Are you an interior decorator? Because when I saw you, the entire room became beautiful.", "If I were a stop light, I'd turn red everytime you passed by, just so I could stare at you a bit longer.", "Does your left eye hurt? Because you've been looking right all day.", "Is Your Name WiFi? Because I'm Really Feeling a Connection.");
				$randomise = rand(0, 4);
				
				echo $slogans[$randomise];
				
				?>
			</div>
			<div class="box">
				<div id=loginHeader>GET STARTED</div>
				<form action="login.php">
					<input class="inputbox" style="margin-top: 40px" type="email" name="email" placeholder="Email Address">
					<input class="inputbox" type="password" name="password" placeholder="Password">
					<br>
					<center><input style="margin-top: 20px" class="button" type="submit" value="Login"></center><br>
				</form>
				<form action="register.php" style="margin-top: -25px">
					<center><input class="button" type="submit" value="Register"></center>
				</form>
				<?php
				
				if ($_GET['logged'] == "in")
				{
					echo '<div><f_success>Successfully logged in!</f_success></div>';
				}
				
				if ($_GET['error'] == "true")
				{
					echo '<div><f_error>Invalid Credentials Entered!</f_error></div>';
				}
				if ($_GET['registered'] == "true")
				{
					echo '<div><f_success>Successfully Created an Account!</f_success></div>';
				}
				?>
			</div>
        </div>
    </body>
	<foot>
		<div id=footer>Created by Johann</div>
	</foot>
</html>