/*
課題０２：	PL/SQLでログ出力するというプロシージャを作成しなさい。
	プロシージャ：Logger（パラメータ１、パラメータ２）
	パラメータ１：ログファイル名
	パラメータ２：出力するメッセージ
	例外の場合、エラーメッセージ：ログ出力は異常に終了しました。は表示される。
*/

create or replace procedure Logger(filename in varchar2, message in varchar2)
is
  dir varchar(20) := 'LOGFILES';
  handler utl_file.file_type;   -- SELECT * FROM ALL_DIRECTORIES; LOGFILES=/home/oracle
  dt varchar(20);
begin
  handler := utl_file.fopen(dir, filename, 'a');
  dt := to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss');
  -- dbms_output.put_line(dbms_utility.format_call_stack);
  utl_file.put_line(handler, dt || ' ' || message);
  utl_file.fclose(handler);
exception
  when others then
    utl_file.fclose_all;
    dbms_output.put_line(dbms_utility.format_error_stack);
end;
------------- end Logger --------------

-- test --
begin
  for i in 1..5 loop
    Logger('wukejia.log', '[' || i || ']');
  end loop;
end;

declare
  refer varchar2(50);
begin
  --refer := SUBSTR(dbms_utility.format_call_stack, 20);
  -- dbms_output.put_line(refer);
  -- dbms_output.put_line(to_char(dbms_utility.get_time, 'yyyy-mm-dd hh24:mi:ss'));
  dbms_output.put_line(dbms_utility.format_call_stack);
end;

SELECT * FROM ALL_DIRECTORIES;

--- create directory and grant privileges by sysdba
create or replace directory exp_dir as '/tmp';
grant read, write on directory exp_dir to wukejia;






declare
  filename varchar(20) := 'wukejia.log';
  message varchar(20) := 'test log file.';
  dir varchar(20) := 'LOGFILES';  -- SELECT * FROM ALL_DIRECTORIES; LOGFILES=/home/oracle
  handler utl_file.file_type;
  dt varchar(20);
begin
  handler := utl_file.fopen(dir, filename, 'a');
  dt := to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss');
  utl_file.put_line(handler, dt || ' ' || message);
  utl_file.fclose(handler);
exception
  when others then
    utl_file.fclose_all;
    dbms_output.put_line(dbms_utility.format_error_stack);
end;