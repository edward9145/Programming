 tail -f /opt/www/tomcat-7.0.39/logs/catalina.out | grep $1 | awk '{print NR "\t" $0}'
