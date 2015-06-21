<?php
echo "name:".$_FILES["file"]["name"];
echo "\ntype:".$_FILES["file"]["type"];
echo "\nsize:".($_FILES["file"]["size"]/1024)."kb\n";
if ($_FILES["file"]["size"] < 2*1024*1024&&$_FILES["file"]["size"] > 1*1024)
	{
	if ($_FILES["file"]["error"] > 0){
		echo "错误代码: " . $_FILES["file"]["error"] . "<br />";
	}
	else{
		$size = getimagesize($_FILES['file']['tmp_name']);
		if($size[0]>10&&$size[1]>10&&$size[0]<50000&&$size[1]<50000)
		{
		if($_FILES["file"]["type"] == "image/png")$destFileName = time().".png";
		else $destFileName = "a.jpg";
		$path = getcwd().'/upload/'.$destFileName;
		echo "Size:".$size[3]."\n";
		$srcFileName = $_FILES['file']['tmp_name'];
		rename($srcFileName, $path);
        echo "上传完毕";
		}else{
			echo "文件格式错误或文件过大";
		}
	}
}
else{
	echo "文件过大或过小";
}
?>