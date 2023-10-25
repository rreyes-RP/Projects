import React from 'react';

const Comments = ({ value, onChange }) => {
  return (
    <div>
      <label>
        Enter any additional information here:
        <textarea value={value} onChange={onChange} />
      </label>
    </div>
  );
};

export default Comments;
