import React, { useState } from 'react';
import QuantityDropdown from './QuantityDropdown';
import MachineDropdown from './MachineDropdown';
import PriorityDropdown from './PriorityDropdown';
import Comments from './Comments';
import CSVUploader from './CsvUploader';

function App() {
  const [quantity, setQuantity] = useState('');
  const [machine, setMachine] = useState('');
  const [priority, setPriority] = useState('');
  const [additionalInfo, setAdditionalInfo] = useState('');
  const [dcmData, setDcmData] = useState([]);

  const handleFileLoaded = (data) => {
    setDcmData(data);
  };

  const handleSubmit = () => {
  const filteredDcms = dcmData.filter((dcm) => dcm.RESERVATION === 'false');
  const firstSetOfDcms = filteredDcms.slice(0, quantity);

  const serialNumbers = firstSetOfDcms.map((dcm) => dcm.SERIAL_NUMBER);

  // Log serial numbers to console
  console.log('Serial Numbers:', serialNumbers);

  // Display in a popup
  alert('Serial Numbers:\n' + serialNumbers.join('\n'));
};


  return (
    <div className="App">
      <h1>DCM Plug Application</h1>
      <div>
        <label>
          Quantity of DCMs to Plug:
          <QuantityDropdown value={quantity} onChange={(e) => setQuantity(e.target.value)} />
        </label>
      </div>
      <div>
        <label>
          Machine:
          <MachineDropdown value={machine} onChange={(e) => setMachine(e.target.value)} />
        </label>
      </div>
      <div>
        <label>
          Priority:
          <PriorityDropdown value={priority} onChange={(e) => setPriority(e.target.value)} />
        </label>
      </div>
      <Comments value={additionalInfo} onChange={(e) => setAdditionalInfo(e.target.value)} />
      <CSVUploader onFileLoaded={handleFileLoaded} />
      <button onClick={handleSubmit}>Submit</button>
    </div>
  );
}

export default App;
