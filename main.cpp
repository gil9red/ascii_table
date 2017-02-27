#include <QStringList>
#include <QDebug>


QString ascii_table(const QList<QStringList>& rows) {
    // Список максимальной ширины столбцов -- каждый элемент это отдельный столбец
    // А шириной будет считаться количество символов
    QList<int> lens;

    const QStringList& headers = rows[0];

    // Перебор по столбцам
    for (int col = 0; col < headers.size(); col++) {
        int max_len = headers[col].size();

        for (int row = 1; row < rows.size(); row++) {
            int cell_len = rows[row][col].size();
            if (cell_len > max_len) {
                max_len = cell_len;
            }
        }

        lens.append(max_len);
    }

    // Генерация шаблона строк таблицы.
    // Если в lens = (2, 15, 3), тогда в formats = ("%-2s", "%-15s", "%-3s")
    // для QString.args = ("%1", "%2", "%3")
    QStringList formats;
    for (int i = 0; i < lens.size(); i++) {
        formats << QString("%%1").arg(i + 1);
    }

    QStringList column_separators;
    for (int col_len : lens) {
        column_separators.append(QString().fill('-', col_len));
    }
    QString separators = column_separators.join("-+-");
    QString pattern = formats.join(" | ");

    QString table;

    for (int row = 0; row < rows.size(); row++) {
        QString row_pattern = pattern;

        for (int col = 0; col < lens.size(); col++) {
            int col_len = lens[col];
            QString cell = rows[row][col];

            // -col_len -- т.е. выравнивание по левой стороне
            row_pattern = row_pattern.arg(cell, -col_len);
        }

        table += row_pattern + "\n";

        // TODO: Так лучше не делать, а разделить генерацию заголовка и тела таблицы
        if (row == 0) {
            table += separators + "\n";
        }
    }

    return table;
}


int main(int argc, char *argv[]) {
    QList<QStringList> rows;
    rows << (QStringList() << "ID" << "NAME"            << "AGE");
    rows << (QStringList() << "1"  << "Ivan Petrov"     << "42");
    rows << (QStringList() << "2"  << "LORD DESTRUCTOR" << "14");
    rows << (QStringList() << "3"  << "Petya"           << "22");

    QString table = ascii_table(rows);
    qDebug().nospace().noquote() << table;

    return 0;
}

