<?php
require 'config.php';
if(!empty($_SESSION["id"]))
{
    $id=$_SESSION["id"];
    $result=mysqli_query($conn,"SELECT * FROM tb_user WHERE id=$id");
    $row=mysqli_fetch_assoc($result);
}
else
{
    header("Location: login.php");
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>USER INFORMATION</title>
</head>
<body>
    <h2>HERE IS YOUR INFORMATION</h2>
    <br>
    <h3>Name: <?php echo $row["name"]; ?></h3>
    <br>
    <h3>Usernam: <?php echo $row["username"]; ?></h3>
    <br>
    <h3>Email: <?php echo $row["email"]; ?></h3>
</body>
</html>