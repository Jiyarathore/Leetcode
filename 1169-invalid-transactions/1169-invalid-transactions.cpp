class Transaction {
    public:
    // name of the person making the transaction
    string personName;
    // time of the transaction in minutes
    int transactionTime; 
    // amount of the transaction
    int transactionAmount;
    // city of the transaction
    string transactionCity;
        
    // constructor for creating transaction object
    Transaction(string name, int time, int amount, string city)
    {
        this->personName = name;
        this->transactionTime = time;
        this->transactionAmount = amount;
        this->transactionCity = city;
    }
};

class Solution {
public:

    // method to find invalid transactions
    vector<string> invalidTransactions(vector<string>& transactions) {
        int numTransactions = transactions.size();
        // boolean flag for each transaction indicating whether it's valid or not
        vector<bool> isValid(numTransactions, true);
        vector<Transaction> inputTransactions;
        
        // Extracting information from string
        for(int i=0; i<numTransactions; i++)
        {
            string currTransaction = transactions[i];
            string name = "", time = "", amount = "", city = "";
            int j = 0;
            
            // Extracting name
            while(currTransaction[j] != ',')
            {
                name += currTransaction[j++];
            }
            j++;
            // Extracting time
            while(currTransaction[j] != ',')
            {
                time += currTransaction[j++];
            }
            j++;
            // Extracting amount
            while(currTransaction[j] != ',')
            {
                amount += currTransaction[j++];
            }
            j++;
            // Extracting city
            while((j < currTransaction.size()) && (currTransaction[j] != ','))
            {
                city += currTransaction[j++];
            }
            
            // Creating a new transaction object with the extracted information
            Transaction newTransaction(name, stoi(time), stoi(amount), city);
            inputTransactions.push_back(newTransaction);
        }
        
        // First check: transaction amount > 1000
        for(int i=0;i<inputTransactions.size(); i++)
        {
            if(inputTransactions[i].transactionAmount > 1000)
                isValid[i] = false;
        }
        
        // Second check, pair-wise
        for(int i=0;i<(inputTransactions.size()); i++)
        {
            for(int j=0; j<inputTransactions.size(); j++)
            {
                // We do not need to check a transaction against itself
                if(i == j)
                    continue;
                    int timeDiff = abs(inputTransactions[j].transactionTime - inputTransactions[i].transactionTime);
            if(timeDiff <= 60)
            {
                if((inputTransactions[j].personName == inputTransactions[i].personName) && (inputTransactions[j].transactionCity != inputTransactions[i].transactionCity))
                {
                    // If the above conditions are met, the transaction is invalid.
                    isValid[i] = false;
                    isValid[j] = false;
                }
            }
        }
    }
    
    // Adding invalid transactions to the answer
    vector<string> invalidTransactions;
    for(int i=0;i<inputTransactions.size(); i++)
    {
        if(!isValid[i])
            invalidTransactions.push_back(transactions[i]);
    }
    
    return invalidTransactions;
}
};