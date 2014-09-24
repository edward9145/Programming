$TOMCAT_8780/bin/shutdown.sh
sleep 5
$TOMCAT_8780/bin/startup.sh
tail -f $TOMCAT_8780/logs/catalina.out
