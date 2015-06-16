<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
<?php
	$file = file_get_contents("now.txt");
	echo "当前文件数:".$file."<br>\n";
	for($i = $file; ($i >= 0) && ($file-$i<10) ; $i--){
		$fn = $i.".jpg";
		$sfn = $i."_small.jpg";
		if(!file_exists($sfn)){
			$img = imagecreatefromjpeg($fn);
			$img = imagescale($img, 711, 400);
			imagejpeg($img, $sfn);
		}
		echo $i.".jpg<br>\n";
		echo "<a href=\"{$sfn}\"><img width=\"711\" height=\"400\" src=".$i.".jpg></a><br><br>\n";
	}
?>