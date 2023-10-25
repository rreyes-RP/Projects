import React from 'react';
import CSVReader from 'react-csv-reader';

const CSVUploader = ({ onFileLoaded }) => {
  const handleFileLoaded = (data, fileInfo) => {
    onFileLoaded(data);
  };

  return <CSVReader onFileLoaded={handleFileLoaded} />;
};

export default CSVUploader;
