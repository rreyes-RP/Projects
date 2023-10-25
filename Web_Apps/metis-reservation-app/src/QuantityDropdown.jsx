import React from 'react';

const QuantityDropdown = ({ value, onChange }) => {
  return (
    <select value={value} onChange={onChange}>
      <option value="">--select--</option>
      {[...Array(16).keys()].map((num) => (
        <option key={num} value={num + 1}>
          {num + 1}
        </option>
      ))}
    </select>
  );
};

export default QuantityDropdown;