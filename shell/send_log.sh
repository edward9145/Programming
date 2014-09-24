tail -f /opt/www/tomcat-7.0.39/logs/catalina.out | grep 'cpName' | awk '{print NR "\t" $2 "\t" substr($5,0,80)}'
