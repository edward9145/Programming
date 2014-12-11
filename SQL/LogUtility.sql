create or replace package LogUtility
as
  logBuffer varchar2(4000) := '';
  
  DIR varchar(20) :=  'LOGFILES';  
  procedure putLog (message in varchar2);
  procedure writeLog(filename in varchar2);
  
  -- handler utl_file.file_type;
  -- procedure lclose;
  -- procedure lopen (filename in varchar2);
end LogUtility;

create or replace package body LogUtility 
as
  procedure putLog (message varchar2) is
    dt varchar(20);
  begin
    dt := to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss');
    logBuffer := logBuffer || dt || ' ' || message || chr(10);
  exception 
    when others then
      dbms_output.put_line(dbms_utility.format_error_stack);
      logBuffer := '';
  end;
  
  procedure writeLog (filename varchar2) is
    handler utl_file.file_type;
  begin
    handler := utl_file.fopen(DIR, filename, 'a');
    utl_file.put(handler, logBuffer);
    utl_file.fclose(handler);
    logBuffer := '';
    
  exception 
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
      logBuffer := '';
  end;
end;


create or replace package body LogUtility 
as
  procedure lopen (filename varchar2) is
  begin
    utl_file.fclose(handler);
    handler := utl_file.fopen(DIR, filename, 'a');
  exception
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
  end lopen;
  
  procedure lappend (message varchar2) is
  begin
    utl_file.put_line(handler, 
        to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss') 
        || ' ' || message);
  exception
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
  end lappend;
  
  procedure lclose is
  begin
    utl_file.fclose(handler);
  end lclose;
  
end LogUtility;

------------------ end LogUtility --------------------

begin
  LogUtility.lopen('wukejia.log');
  for i in 1..5 loop
    LogUtility.lappend(i);
  end loop;
  LogUtility.lopen('wkj.log');
  for i in 6..10 loop
    LogUtility.lappend(i);
  end loop;
  LogUtility.lclose();
end;



create or replace package body LogUtility 
as
  procedure lopen(filename varchar2) is
  begin
    utl_file.fclose(handler);
    handler := utl_file.fopen(DIR, filename, 'a');
  exception
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
  end lopen;
  
  procedure lappend(message varchar2) is
  begin
    if handler is not null then
      utl_file.put_line(handler, 
        to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss') 
        || ' ' || message);
    else
      dbms_output.put_line('no log file is open.');
    end if;
  exception
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
  end lappend;
  
  procedure lclose is
  begin
    if handler is not null then
      utl_file.fclose(handler);
    else
      dbms_output.put_line('no log file is open.');
    end if;
  exception
    when others then
      utl_file.fclose_all;
      dbms_output.put_line(dbms_utility.format_error_stack);
  end lclose;
  
end LogUtility;


/*
CREATE or replace PACKAGE emp_stuff AS
  -- Declare cursor spec
  CURSOR c1 RETURN EMP%ROWTYPE;
END emp_stuff;
*/

begin
  dbms_output.put('abcdef'||chr(10)||chr(13)||'hjkml');
end;

declare
  handler utl_file.file_type; 
begin
  if handler then
    utl_file.put_line(handler, 
        to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss'));
    utl_file.fclose(handler);
  end if;
end;

declare
  lstart number;
  lend number;
  ldiff number;
  j number;
begin
  lstart := dbms_utility.get_time;
  for i in 1..10000 loop
    j := j + i;
    for k in 1..1000 loop
      j := j + k;
    end loop;
  end loop;
  lend := dbms_utility.get_time;
  ldiff := (lend-lstart)/100;
  dbms_output.put_line('start: ' || lstart);
  dbms_output.put_line('end: ' || lend);
  dbms_output.put_line('diff: ' || ldiff);
end;