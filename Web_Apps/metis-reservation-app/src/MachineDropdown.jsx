import React from 'react';

const MachineDropdown = ({ value, onChange }) => {
  return (
    <select value={value} onChange={onChange}>
      <option value="">--select--</option>
      {['B01', 'B02', 'B03', 'B04', 'B05'].map((machine) => (
        <option key={machine} value={machine}>
          {machine}
        </option>
      ))}
    </select>
  );
};

export default MachineDropdown;
