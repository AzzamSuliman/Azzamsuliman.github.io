<?php
//Creates new record as per request
    //Connect to database
    $servername = "192.168.0.189";		//example = localhost or 192.168.0.0
    $username = "root";		//example = root
    $password = "";	
    $dbname = "esp";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }

    //Get current date and time
    date_default_timezone_set('Asia/Jakarta');
    $d = date("Y-m-d");
    $t = date("H:i:s");

    if(!empty($_POST['ldrvalue']))
    {
		$ldrvalue = $_POST['ldrvalue'];
	    $sql = "INSERT INTO nodemcu_ldr_table (Ldr, Date, Time) VALUES ('".$ldrvalue."', '".$d."', '".$t."')"; //nodemcu_ldr_table = Youre_table_name

		if ($conn->query($sql) === TRUE) {
		    echo "OK";
		} else {
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
	}


	$conn->close();
?>