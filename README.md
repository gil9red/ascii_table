# ascii_table
Ascii table (#c++ #qt #qt5)

#### Example:
```
QList<QStringList> rows;
rows << (QStringList() << "ID" << "NAME"            << "AGE");
rows << (QStringList() << "1"  << "Ivan Petrov"     << "42");
rows << (QStringList() << "2"  << "LORD DESTRUCTOR" << "14");
rows << (QStringList() << "3"  << "Petya"           << "22");

QString table = ascii_table(rows);
qDebug().nospace().noquote() << table;
```

#### Console:
```
 ID | NAME            | AGE
----+-----------------+----
 1  | Ivan Petrov     | 42 
 2  | LORD DESTRUCTOR | 14 
 3  | Petya           | 22 
```
