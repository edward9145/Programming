cd $WEBAPP_8780
mv -f DoctorAdmin.war DoctorAdmin.war.bak
rz
$TOMCAT_8780/bin/shutdown.sh
sleep 5
rm -rf DoctorAdmin
$TOMCAT_8780/bin/startup.sh
tail -f $TOMCAT_8780/logs/catalina.out
