int mosChecker(){
    double m;
    int month;
    bool valid = true;

    cout<<"Enter month: ";
     
while (valid){
    if (!(cin>>m) || (m != int(m))){       // check if the input is non-integer and decimal   
        cout<<"Invalid\n";
        cout<<"Enter month: ";
        cin.clear();
        cin.ignore(1000, '\n');
        valid = true;
        continue;
    }


    month = int(m); 


    if (month < 1 || month > 12){ 
    cout<<"Invalid";
    valid = true;
    continue;
    }
    else{
        valid = false;
    }
}

return month;
}