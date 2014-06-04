drop table if exists yk_app;

/*==============================================================*/
/* Table: yk_app                                                */
/*==============================================================*/
create table yk_app
(
   ts                   timestamp default CURRENT_TIMESTAMP,
   id                   varchar(36) not null comment '主键',
   name                 varchar(50) comment '应用名称',
   description          varchar(1000) comment '应用描述',
   version              varchar(50) comment '当前版本',
   developer            varchar(50) comment '开发商',
   copyright            varchar(50) comment '版权',
   contact              varchar(50) comment '联系方式',
   dr                   smallint default 0,
   primary key (id)
);

alter table yk_app comment '益康_应用信息';

drop table if exists yk_app_version;

/*==============================================================*/
/* Table: yk_app_version                                        */
/*==============================================================*/
create table yk_app_version
(
   ts                   timestamp default CURRENT_TIMESTAMP,
   id                   varchar(36) not null comment '主键',
   yk_app_id            varchar(36) comment '益康_应用_主键',
   update_info          varchar(1000) comment '版本更新信息',
   version              varchar(50) comment '版本号',
   size                 int comment '应用大小(byte)',
   url                  varchar(100) comment '应用下载地址',
   dr                   smallint default 0,
   primary key (id)
);

alter table yk_app_version comment '益康_应用_版本';

