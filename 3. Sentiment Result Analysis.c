void sentiment::SLT_process()
{
    int files  = ui->db->text().toInt();
    QString out = ui->out->text()+"_out.txt";

    for(int i = 1; i<=files; i++)
    {
        if(i<10)
        {
            QString raw = ui->raw->text()+"0" + QString::number(i) + ".csv";
            QString time = ui->raw->text()+"0" + QString::number(i) + ".txt";
            SLT_process_run(raw, time, out);
        }
        else
        {
            QString raw = ui->raw->text() + QString::number(i) + ".csv";
            QString time = ui->raw->text() + QString::number(i) + ".txt";
            SLT_process_run(raw, time, out);
        }
    }

}

void sentiment::SLT_process_run(QString raw, QString time, QString out)
{


    float pos = ui->pos->text().toFloat();
    float neg = ui->neg->text().toFloat();

    QList<raw_s> raw_list;
    QList<time_s> time_list;

    raw_list.clear();
    time_list.clear();

    QFile raw_file(raw);
    QFile time_file(time);

    //Try open the file
    if (raw_file.open(QFile::ReadOnly))
    {
        //Read file
        QTextStream in(&raw_file);
        QStringList itemParams;
        while (!in.atEnd())
        {
            itemParams = in.readLine().split(QRegExp(","), QString::SkipEmptyParts);
            if(itemParams.size() == 2){
                raw_s raw_data;
                bool ok = 1;
                raw_data.ID = itemParams[0];
                raw_data.sentiment = itemParams[1].toFloat(&ok);
                //If decode success, then add it into the cargo_info_list
                if (ok)
                {
                    raw_list.append(raw_data);
                }
            }
        } //read finished
    }

    //Try open the file
    if (time_file.open(QFile::ReadOnly))
    {
        //Read file
        QTextStream in(&time_file);
        QStringList itemParams;
        while (!in.atEnd())
        {
            itemParams = in.readLine().split(QRegExp(","), QString::SkipEmptyParts);
            if(itemParams.size() == 2){
                time_s time_data;
                time_data.ID = itemParams[0];
                time_data.dt = itemParams[1];
                time_list.append(time_data);
            }
        } //read finished
    }

    QFile file(out);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {

        QString output = QString("datetime, postive, negative, netural, total\n");
        QTextStream out(&file);
        out << output;
        out.flush();
    }

    int c = 0;
    for(int t= 0; t<time_list.size(); t++)
    {
        out_s outs{};
        outs.dt = time_list[t].dt;
        for(int i= c; i<raw_list.size(); i++)
        {
            if(raw_list[i].ID!=time_list[t].ID)
            {
                if(raw_list[i].sentiment>=pos)
                    outs.pos_c++;
                else if(raw_list[i].sentiment<=neg)
                    outs.neg_c++;
                else if(raw_list[i].sentiment > neg && raw_list[i].sentiment < pos)
                    outs.mid_c++;
                outs.total_c++;
            }
            else
            {
                QString output = QString("%1,%2,%3,%4,%5\n")
                    .arg(outs.dt)
                    .arg(outs.pos_c)
                    .arg(outs.neg_c)
                    .arg(outs.mid_c)
                    .arg(outs.total_c);
                QTextStream out(&file);
                out << output;
                out.flush();

                c = i;
                break;
            }
        }
    }
}

void sentiment::SLT_process2()
{
    QString db  = ui->db->text()+".csv";
    QString out = ui->out->text()+"_out.txt";

    float pos = ui->pos->text().toFloat();
    float neg = ui->neg->text().toFloat();

    QList<raw_s> db_list;

    db_list.clear();

    QFile db_file(db);

    //Try open the file
    if (db_file.open(QFile::ReadOnly))
    {
        //Read file
        QTextStream in(&db_file);
        QStringList itemParams;
        while (!in.atEnd())
        {
            itemParams = in.readLine().split(QRegExp(","), QString::SkipEmptyParts);
            if(itemParams.size() == 2){
                raw_s db_data;
                bool ok = 1;
                db_data.ID = itemParams[0];
                db_data.sentiment = itemParams[1].toFloat(&ok);
                //If decode success, then add it into the cargo_info_list
                if (ok)
                {
                    db_list.append(db_data);
                }
            }
        } //read finished
    }

    QFile file(out);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {

        QString output = QString("datetime, postive, negative, netural, total\n");
        QTextStream out(&file);
        out << output;
        out.flush();
    }

    int c = 0;
    out_s outs{};
    for(int t= 0; t<db_list.size(); t++)
    {
        if(db_list[t].ID == "new")
        {
            QString output = QString("%1,%2,%3,%4,%5\n")
                .arg(outs.dt)
                .arg(outs.pos_c)
                .arg(outs.neg_c)
                .arg(outs.mid_c)
                .arg(outs.total_c);
            QTextStream out(&file);
            out << output;
            out.flush();

            outs.dt = db_list[t+1].ID;
            outs.pos_c = 0;
            outs.neg_c = 0;
            outs.mid_c = 0;
            outs.total_c = 0;
        }

        if(db_list[t].sentiment>=pos)
            outs.pos_c++;
        else if(db_list[t].sentiment<=neg)
            outs.neg_c++;
        else if(db_list[t].sentiment > neg && db_list[t].sentiment < pos)
            outs.mid_c++;
        outs.total_c++;
    }
}
