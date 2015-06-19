<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
<?php
	$ye = $_GET['ye'];
	$file = file_get_contents("now.txt");
	echo "当前文件数:".$file."<br>\n";
	$asd = $file - $ye*5;
	for($i = 0; $i<5; $i++){
		$fn = ($asd-$i).".jpg";
		echo $fn."<br>\n";
		echo "<a href={$fn}><img style=\"width: 80%\" src={$fn}></a><br><br>\n";
	}
	$ye++;
	echo "<a href=index.php?ye={$ye}>第{$ye}页</a>"
?>
