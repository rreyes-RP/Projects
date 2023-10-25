const express = require('express');
const { execSync } = require('child_process');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.post('/generateTicket', (req, res) => {
  const { machine, additionalInfo, priority, w3id, password } = req.body;

  if (!machine || !additionalInfo || !priority || !w3id || !password) {
    return res.status(400).send('Please provide all required fields.');
  }

  const serialNumbers = req.body.serialNumbers.join('\n');
  const priorityString = mapPriority(priority);

  const cmd = `/usr/bin/python /Users/roriereyes/Documents/rtcwi/rtcwi/scripts/rtcwi.py create Ticket Summary : "${machine} DCM Swap", "Description" : "${additionalInfo}", "Parts To Install" : "${serialNumbers}", "Difficulty" : "Medium", "Filed Against" : "Change chips", "Machine" : "${machine}", "Priority" : "${priorityString}", "Project Area" : "EST Technology Test (Change Management)", "Projects" : "Artemis", "Type" : "Ticket" -u ${w3id} -r https://jazz-zsa.rchland.ibm.com/ccm -p "EST Technology Test (Change Management)"`;

  try {
    const output = execSync(cmd, { encoding: 'utf-8', input: `${password}\n` });
    return res.send(output);
  } catch (error) {
    return res.status(500).send('An error occurred while generating the ticket.');
  }
});

function mapPriority(priority) {
  switch(priority) {
      case '1':
          return 'Now!!!';
      case '2':
          return 'High';
      case '3':
          return 'Medium';
      case '4':
          return 'Low';
      default:
          return '';
  }
}

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
