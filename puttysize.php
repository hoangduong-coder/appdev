<?php
/*
$row = $_POST['row'];
$col = $_POST['col'];
*/
$peak = $_POST['peak'];
$maxdB = $_POST['maxdB'];
$today = date("Y-m-d H:i:s");
$record = $today . ", Number of peak: " . $peak . ", Maximum decibel: " . $maxdB . "\n";

$file = "putty.txt";
if(file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");

fwrite($fp, $record);
fclose($fp);

echo "From e1900281 \n";
?>
