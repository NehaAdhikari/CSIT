#Lab 6
##Implement Auto increment column using sequence and trigger
create sequence <seq_tablename_primarykey>;
create before insert trigger:
        if new.pk_column is null then
            new.pk_column = seq_table_pk.nextval;
        end if;
