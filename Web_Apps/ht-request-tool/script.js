function handleSubmit() {
    const csvFile = document.getElementById('csvFile').files[0];
    const quantity = parseInt(document.getElementById('quantity').value, 10);
    const w3id = document.getElementById('w3id').value;
    const password = document.getElementById('password').value;
    const machine = document.getElementById('machine').value;
    const priority = document.getElementById('priority').value;

    // Check if any of the mandatory fields are empty
    if (!csvFile || isNaN(quantity) || quantity < 1 || !w3id || !password || machine === '' || priority === '') {
        alert('Please fill out all mandatory fields and enter a valid quantity.');
        return;
    }

    const reader = new FileReader();
    reader.onload = function(event) {
        const csvData = event.target.result;

        Papa.parse(csvData, {
            complete: function(result) {
                const header = result.data[0];
                const rows = result.data.slice(1);

                const serialNumbers = [];
                rows.forEach(row => {
                    if (row.length >= 2) {
                        const reservation = row[1].trim().toLowerCase();
                        if (reservation === 'false') {
                            serialNumbers.push(row[0].trim());
                        }
                    }
                });

                const firstSetOfSerialNumbers = serialNumbers.slice(0, quantity);

                if (firstSetOfSerialNumbers.length > 0) {
                    const additionalInfo = document.getElementById('additionalInfo').value;

                    const serialNumbersTable = document.getElementById('serialNumbersTable');
                    const tbody = serialNumbersTable.querySelector('tbody');

                    firstSetOfSerialNumbers.forEach(serialNumber => {
                        const row = document.createElement('tr');
                        const cell = document.createElement('td');
                        cell.textContent = serialNumber;
                        row.appendChild(cell);
                        tbody.appendChild(row);
                    });

                    // Hide the form and display the table
                    document.getElementById('formContainer').style.display = 'none';
                    document.getElementById('serialNumbersTableContainer').style.display = 'block';
                } else {
                    alert('No DCMs with reservation as "false".');
                }
            }
        });
    };

    reader.onerror = function() {
        alert('Error reading the file. Please make sure it is a valid CSV file.');
    };

    reader.readAsText(csvFile);

}

function resetFields() {
    // Reset form fields
    document.getElementById('quantity').value = '';
    document.getElementById('w3id').value = '';
    document.getElementById('password').value = '';
    document.getElementById('machine').value = '';
    document.getElementById('priority').value = '';
    document.getElementById('additionalInfo').value = '';
}

function generateTicket() {
  const machine = document.getElementById('machine').value;
  const additionalInfo = document.getElementById('additionalInfo').value;
  const priority = document.getElementById('priority').value;
  const w3id = document.getElementById('w3id').value;
  const password = document.getElementById('password').value;

  const serialNumbersTable = document.getElementById('serialNumbersTable');
  const serialNumbers = Array.from(serialNumbersTable.querySelectorAll('tbody tr td')).map(cell => cell.textContent);

  if (!machine || !additionalInfo || !priority || !w3id || !password || !serialNumbers.length) {
    alert('Please fill out all mandatory fields.');
    return;
  }

  const requestBody = {
    machine,
    additionalInfo,
    priority,
    w3id,
    password,
    serialNumbers
  };

  fetch('http://localhost:3000/generateTicket', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify(requestBody)
  })
  .then(response => response.text())
  .then(ticket => {
    alert(`Ticket generated successfully. Ticket ID: ${ticket}`);
  })
  .catch(error => {
    console.error('Error:', error);
    alert('An error occurred while generating the ticket.');
  });

  resetFields();
}


