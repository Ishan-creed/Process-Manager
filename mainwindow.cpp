#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label1->setHidden(true);
    ui->label2->setHidden(true);
    ui->label3->setHidden(true);
    ui->label4->setHidden(true);
    ui->label5->setHidden(true);
    ui->label6->setHidden(true);
    ui->label7->setHidden(true);
    ui->startwindow->setHidden(true);
    ui->table->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->tab->setHidden(true);
    ui->run->setHidden(true);
    ui->close->setHidden(true);
    // Install event filter to listen for mouse clicks on the screen
    qApp->installEventFilter(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_startButton_clicked()
{
    ui->startwindow->setHidden(false);
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        // Check if the clicked object is not the list widget or one of its child widgets
//        if (obj != ui->startwindow && !ui->startwindow->isAncestorOf(static_cast<QWidget*>(obj))) {
            // Hide labels when the user clicks outside the list widget
//            ui->label1->setHidden(true);
//            ui->label2->setHidden(true);
//            ui->label3->setHidden(true);
//            ui->label4->setHidden(true);
//            ui->label5->setHidden(true);
//            ui->label6->setHidden(true);
//            ui->label7->setHidden(true);
        }
//    }
    return false;
}
void MainWindow::on_startwindow_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "Operating System Project") {
        ui->label1->setHidden(false);
        ui->textEdit->setHidden(false);
        ui->run->setHidden(false);
        ui->close->setHidden(false);
        ui->tab->setHidden(false);
    }
    else if (item->text() == "Counter-Strike: Global Offensive") {
        ui->label2->setHidden(false);
        ui->label2->setText("Opening Counter-Strike: Global Offensive so that ishan can break the shit out of his mouse");
    }
    else if (item->text() == "Dota") {
        ui->label3->setHidden(false);
        ui->label3->setText("Opening Dota so that ishan can break the shit out of his mouse");
    }
    else if (item->text() == "Destiny") {
        ui->label4->setHidden(false);
        ui->label4->setText("Opening Destiny so that ishan can break the shit out of his mouse");
    }
    else if (item->text() == "Elden Ring") {
        ui->label5->setHidden(false);
        ui->label5->setText("Opening Elden Ring so that ishan can break the shit out of his mouse");
    }
    else if (item->text() == "The Witcher 3: Wild Hunt") {
        ui->label6->setHidden(false);
        ui->label6->setText("Opening The Witcher 3: Wild Hunt so that ishan can break the shit out of Keshav at Night");
    }
    else if (item->text() == "Apex Legends") {
        ui->label7->setHidden(false);
        ui->label7->setText("Opening Apex Legends so that ishan can break the shit out of his mouse");
    }
}
void MainWindow::runCode()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int num_proc;
    int randomNumber = std::rand() % 10 + 1;
    num_proc = randomNumber;
    ui->textEdit->append("The number of processes we have are: " + QString::number(num_proc));
    int at[num_proc];
    int bt[num_proc];
    int mem_demand[num_proc];
    int memory_blocks[10];
    int resource_needed[num_proc];
    int max_need[num_proc];
    int res_avail[num_proc];
    int cpu_avail = std::rand() % 20 + 10;
    for (int i = 0; i < num_proc; i++)
    {
        int arrivalNumber = std::rand() % 10 + 1;
        ui->textEdit->append("The arrival time for process " + QString::number(i) + " is: " + QString::number(arrivalNumber));
        at[i] = arrivalNumber;
    }
    for (int i = 0; i < num_proc; i++)
    {
        int BurstNumber = std::rand() % 20 + 1;
        ui->textEdit->append("The burst time for process " + QString::number(i) + " is: " + QString::number(BurstNumber));

        bt[i] = BurstNumber;
    }
    for (int i = 0; i < num_proc; i++)
    {
        int MemoryDemand = std::rand() % 20 + 1;
        ui->textEdit->append("The Memory demand for process " + QString::number(i) + " is: " + QString::number(MemoryDemand));
        mem_demand[i] = MemoryDemand;
    }
    int size = 0;
    for (int i = 0; i < num_proc; i++)
    {
        int BlockSize = std::rand() % 20 + 10;
        ui->textEdit->append("The Block size for block " + QString::number(i) + " is: " + QString::number(BlockSize));
        memory_blocks[i] = BlockSize;
        size += 1;
    }
    for(int i = 0 ; i<num_proc;i++){
        int res_avail1 = std::rand() % 20 + 1;
        ui->textEdit->append("The no of resources available in  process " + QString::number(i) + " is: " + QString::number(res_avail1));
        res_avail[i] = res_avail1;
    }
    for(int i = 0 ; i<num_proc;i++){
        int res_needed1 = std::rand() % 20 + 1;
        ui->textEdit->append("The resource needed for process "+ QString::number(i) + " is: "+ QString::number(res_needed1));
        resource_needed[i] = res_needed1;
    }
    for(int i = 0 ; i<num_proc;i++){
        int max_res = std::rand() % 20 + 1;
        ui->textEdit->append("The maximum resource needed by process "+ QString::number(i) +" is: "+ QString::number(max_res));
        max_need[i] = max_res;
    }
    fcfs(bt, at, num_proc);
    memory_alloc(mem_demand, memory_blocks, num_proc, size);
    dead(resource_needed,max_need,res_avail,cpu_avail,num_proc);
}

void MainWindow::fcfs(int bt[], int at[], int n)
{
    int wt[n];
    int ct[n];
    int tat[n];
    int avg_wt[n];
    int avg_tat[n];
    float tavg = 0;
    float wavg = 0;

    for (int i = 0; i < n; i++)
    {
        ct[i] = at[i] + bt[i];
        wt[i] = ct[i] - bt[i];
        tat[i] = ct[i] - at[i];
        avg_wt[i] = wt[i];
        avg_tat[i] = tat[i];
    };

    for (int i = 0; i < n; i++)
    {
        tavg += avg_tat[i];
        wavg += avg_wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        ui->textEdit->append("Completion time for process " + QString::number(i) + " is: " + QString::number(ct[i]));
        ui->textEdit->append("Waiting time for process " + QString::number(i) + " is: " + QString::number(wt[i]));
        ui->textEdit->append("Turnaround time for process " + QString::number(i) + " is: " + QString::number(tat[i]));
    }
    ui->textEdit->append("Average waiting time comes out to be: " + QString::number(wavg / n));
    ui->textEdit->append("Average turn around time comes out to be: " + QString::number(tavg / n));
}
void MainWindow::memory_alloc(int demand[], int block_size[], int n, int k)
{
    int allocated[10];
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (block_size[j] >= demand[i])
            {
                ui->textEdit->append("Process " + QString::number(i) + " allocated to block " + QString::number(j) + " with block size: " + QString::number(block_size[j]));

                block_size[j] = block_size[j] - demand[i];
                ui->textEdit->append("Remaining block size of current block = " + QString::number(block_size[j]));

                break;
            }
        }
    }
}
void MainWindow::dead(int res_needed[],int max_needed[],int avail[],int cpu_avail, int n)
{
    int sequence[n];
    int count = 0;
    ui->textEdit->append("Total processes requesting resources are: " + QString::number(n) + "\n");
    for(int i = 0; i<n; i++){
        if(res_needed[i]<=cpu_avail){
            cpu_avail = cpu_avail - res_needed[i];
            ui->textEdit->append("Resource allocated to process "+QString::number(i)+" for the resource amount " + QString::number(res_needed[i]));
            cpu_avail = cpu_avail + max_needed[i];
            ui->textEdit->append("After releasing the resource the current available resource count in cpu is: " + QString::number( cpu_avail));
            count++;
        }
    }
    if(count<n){
        ui->textEdit->append("Deadlock was found in the system !");
    }
}
void MainWindow::on_run_clicked()
{
    ui->label1->setText("Process manager is running");
    runCode();
}
void MainWindow::on_tab_clicked()
{
    ui->table->setHidden(false);

}
void MainWindow::on_close_clicked()
{
    ui->label1->setText("Process manager closed");
    ui->table->setHidden(true);
    ui->textEdit->clear();
    ui->textEdit->setHidden(true);
    ui->tab->setHidden(true);
    ui->run->setHidden(true);
    ui->close->setHidden(true);
    ui->label1->setHidden(true);
}
