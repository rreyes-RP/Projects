import React from 'react';

const PriorityDropdown = ({ value, onChange }) => {
  return (
    <select value={value} onChange={onChange}>
      <option value="">--select--</option>
      {[1, 2, 3, 4].map((priority) => (
        <option key={priority} value={priority}>
          {priority}
        </option>
      ))}
    </select>
  );
};

export default PriorityDropdown;
