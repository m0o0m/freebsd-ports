--- www/diagram/diagram_bars.php.orig	Thu Jan 11 05:43:48 2007
+++ www/diagram/diagram_bars.php	Thu Jan 11 20:22:30 2007
@@ -105,23 +105,6 @@
 	$prevDOfMonth=$DayOfMonth;
     }
 
-    $Columns = sizeof($allDays);
-    if($Columns > 30){                             
-	$delta = ceil($Columns/30);                
-                                                   
-	$giveDelta=0;                              
-	while (list($key, $val) = each($allDays)) {
-    	    if($giveDelta == $key){                
-        	$giveDelta+=$delta;                
-    	    }else{                                 
-        	$allDays[$key][0]='';              
-    	    }                                      
-    	    if($val[1] > $maxValue){               
-        	$maxValue=$val[1];                 
-    	    }
-	}                                          
-    }
-
 if($debug) print_r($allDays);
 if($debug) print("I".$maxValue."I");
 
